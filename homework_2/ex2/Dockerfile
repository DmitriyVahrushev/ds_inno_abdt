FROM python:2-buster


RUN mkdir -p /home/brat_app
WORKDIR /home/brat_app

#скачивание архива с brat , копирование скриптов 
RUN wget http://weaver.nlplab.org/~brat/releases/brat-v1.3_Crunchy_Frog.tar.gz
COPY start.sh /home/brat_app/
COPY input_data.exp /home/brat_app/

RUN chmod +x start.sh
RUN tar xzf brat-v1.3_Crunchy_Frog.tar.gz
RUN apt update
RUN apt -y install expect
#если не удалить, то будет конфликтовать с модулем filelock в server/src
RUN pip uninstall -y filelock 

EXPOSE 8001

ENV username admin
ENV password 123
ENV admin_email admin@mail.org


CMD ./start.sh $username $password $admin_email
