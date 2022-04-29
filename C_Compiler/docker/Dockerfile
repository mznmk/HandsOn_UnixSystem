# [ base image ]
FROM    ubuntu:focal

# [ system update ]
# [ install application ]
RUN     apt-get update; \
        DEBIAN_FRONTEND=noninteractive apt-get install -y gcc make git binutils libc6-dev gdb sudo bash-completion;

# [ set user environment ]
RUN     adduser --disabled-password --gecos '' user
RUN     echo 'user ALL=(root) NOPASSWD:ALL' > /etc/sudoers.d/user
USER    user

# [ set working directory ]
WORKDIR /home/user
