FROM python:2-buster


RUN mkdir -p /home/brat_app
WORKDIR /home/brat_app

RUN wget http://weaver.nlplab.org/~brat/releases/brat-v1.3_Crunchy_Frog.tar.gz
COPY brat-v1.3_Crunchy_Frog.tar.gz /home/brat_app/
COPY start.sh /home/brat_app/
COPY input_data.exp /home/brat_app/

RUN chmod +x start.sh
RUN tar xzf brat-v1.3_Crunchy_Frog.tar.gz
RUN apt update
RUN apt -y install expect
RUN pip uninstall -y filelock

EXPOSE 8001

ENV username admin
ENV password 123
ENV admin_email admin@mail.org


CMD ./start.sh $username $password $admin_email
