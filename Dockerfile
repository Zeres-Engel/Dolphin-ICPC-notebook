FROM ubuntu:22.04

# Avoid prompts from apt
ENV DEBIAN_FRONTEND=noninteractive

# Install required packages
RUN apt-get update && apt-get install -y \
    python3 \
    python3-pip \
    texlive-latex-base \
    texlive-latex-extra \
    texlive-fonts-recommended \
    texlive-lang-all \
    make \
    g++ \
    git \
    vim \
    bc \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Set up vim configuration
RUN echo "syntax on\nset number\nset tabstop=4\nset shiftwidth=4\nset expandtab" > ~/.vimrc

# Set working directory
WORKDIR /notebook

# Add build aliases
RUN echo 'alias build="make kactl"' >> ~/.bashrc && \
    echo 'alias quick="make fast"' >> ~/.bashrc && \
    echo 'alias clean="make clean"' >> ~/.bashrc && \
    echo 'alias test="make test"' >> ~/.bashrc

# Keep container running
CMD ["/bin/bash"]