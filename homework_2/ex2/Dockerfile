FROM python:2.7
RUN mkdir app

WORKDIR /home/dmitriy/data_science_innoabdt/app/
COPY brat-v1.3_Crunchy_Frog.tar.gz /home/dmitriy/data_science_innoabdt/app/
RUN tar xzf brat-v1.3_Crunchy_Frog.tar.gz
EXPOSE 8001
CMD ["./brat-v1.3_Crunchy_Frog/install.sh", "-u"]
