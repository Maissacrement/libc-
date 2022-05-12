FROM ubuntu

ENV TZ=Europe/Paris
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

COPY ./config config
WORKDIR /config

RUN apt update &&\
    apt install python3 python3-pip cmake g++ -y

# CREATE USER
ENV USER=conan \
    uid=1000 gid=1000

ENV DEV_HOME="/home/${USER}" \
    CONAN_BIN=/home/conan/.local/bin \
    CONAN_LIB=/home/conan/.local/lib

ENV PATH=${PATH}:${CONAN_BIN}:${CONAN_LIB}

COPY ./src ${DEV_HOME}/app

RUN mkdir -p ${DEV_HOME} ${DEV_HOME}/app ${CONAN_BIN} ${CONAN_LIB} && \
    echo "${USER}:x:${uid}:${gid}:${USER},,,:${DEV_HOME}:/bin/bash" >> /etc/passwd && \
    echo "${USER}:x:${uid}:" >> /etc/group &&\
    chown -R ${USER}:${USER} ${DEV_HOME} ${CONAN_BIN} ${CONAN_LIB}

USER ${USER}

RUN pip3 install -r requirements.txt --upgrade

WORKDIR ${DEV_HOME}/app