# Imagem base: Ubuntu 22.04
FROM ubuntu:22.04

# Argumento para o nome de utilizador não-root
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Evita prompts interativos durante a instalação de pacotes
ENV DEBIAN_FRONTEND=noninteractive

# Instala as dependências essenciais para desenvolvimento em C e outras ferramentas úteis
RUN apt-get update && apt-get install -y \
    sudo \
    build-essential \
    gdb \
    valgrind \
    git \
    curl \
    vim \
    && rm -rf /var/lib/apt/lists/*

# Cria um utilizador não-root e define bash como o seu shell padrão
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m -s /bin/bash $USERNAME \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# Muda para o utilizador não-root
USER $USERNAME

# Define o diretório de trabalho
WORKDIR /home/$USERNAME/workspace

# Comando para manter o contêiner a funcionar
CMD [ "sleep", "infinity" ]
