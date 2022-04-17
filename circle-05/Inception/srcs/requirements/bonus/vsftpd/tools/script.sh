# !/bin/sh

# Check Whether Change on Configuration File is Needed or Not
if [ ! -f "/etc/vsftpd/vsftpd.conf" ]; then
  # Wait for the Other Containers
  sleep 5;
  # Copy Configuration File
  cp /tmp/vsftpd.conf /etc/vsftpd/vsftpd.conf
  # Add User for FTP
  adduser $FTP_USER --disabled-password --gecos "" --home /home/$FTP_USER --shell /bin/sh
  # Set Password for User
  echo "$FTP_USER:$FTP_PWD" | chpasswd > /dev/null
  # Set User's Initial Root Path
  echo "local_root=$FTP_ROOT" >> /etc/vsftpd/vsftpd.conf
fi

# Set Permission and Ownership
chgrp -R $FTP_USER $FTP_ROOT
chown -R $FTP_USER $FTP_ROOT
chmod -R +x $FTP_ROOT

# Run by Dumb Init
vsftpd /etc/vsftpd/vsftpd.conf
