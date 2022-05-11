FROM ubuntu

COPY ./config config
WORKDIR /config

RUN apt update &&\
    apt install python3 python3-pip -y

RUN pip3 install -r requirements.txt --upgrade

# CREATE USER
ENV USER=conan
ENV DEV_HOME=/home/${USER} \
    uid=1000 gid=1000

RUN mkdir -p ${DEV_HOME} ${DEV_HOME}/app && \
    echo "${USER}:x:${uid}:${gid}:${USER},,,:${DEV_HOME}:/bin/bash" >> /etc/passwd && \
    echo "${USER}:x:${uid}:" >> /etc/group

COPY ./src ${DEV_HOME}/app
WORKDIR ${DEV_HOME}/app
