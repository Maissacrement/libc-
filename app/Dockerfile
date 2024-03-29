FROM ubuntu:20.04

ENV TZ=Europe/Paris
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

COPY ./config config
WORKDIR /config

RUN apt update

RUN apt install python3 python3-pip cmake g++-10 cppcheck vim -y

# CREATE USER
ENV USER=conan \
    uid=1000 gid=1000

ENV DEV_HOME="/home/${USER}" \
    CONAN_BIN=/home/conan/.local/bin \
    CONAN_LIB=/home/conan/.local/lib

ENV PATH=${PATH}:${CONAN_BIN}:${CONAN_LIB}

RUN mkdir -p ${DEV_HOME}/app/src
COPY ./CMakeLists.txt ${DEV_HOME}/app/
COPY ./src ${DEV_HOME}/app/src

RUN mkdir -p ${DEV_HOME} ${DEV_HOME}/app ${CONAN_BIN} ${CONAN_LIB} ${DEV_HOME}/.conan/profiles/ && \
    echo "${USER}:x:${uid}:${gid}:${USER},,,:${DEV_HOME}:/bin/bash" >> /etc/passwd && \
    echo "${USER}:x:${uid}:" >> /etc/group

RUN pip3 install -r requirements.txt --upgrade

RUN cp /config/profile_conan ${DEV_HOME}/.conan/profiles/default
RUN chown -R ${USER}:${USER} ${DEV_HOME} ${CONAN_BIN}

USER ${USER}
RUN conan config init
RUN chown -R ${USER}:${USER} ${CONAN_LIB}

WORKDIR ${DEV_HOME}/app

ENTRYPOINT [ "tail", "-f", "/dev/null" ]