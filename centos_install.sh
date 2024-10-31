echo "Installation program for openInventory on CentOS 7+ based systems"
echo "This script will install the required packages and configure the system"
echo "This script must be run with sudo privilege."
echo "Do not forget to chmod +x the script."
echo

mkdir log/

# Update the system
echo "Updating the system"
sudo dnf -y update > /dev/null && sudo dnf -y upgrade && sudo dnf -y install git && git clone https://github.com/NewMaxT/openInventory-server.git > log/update.log
rm openInventory-server/centos_install.sh
echo

# Install required packages
echo "Installing required packages"
sudo dnf -y install gcc g++ make cmake3 openssl-devel mysql-devel postgresql-devel

# Building the project
echo "Building the project (Log in log/build.log)"
cmake -B build/ -S openInventory-server/ > log/build.log