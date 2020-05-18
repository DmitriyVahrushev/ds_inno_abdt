FROM python:latest
RUN mkdir -p /home/flask_app
WORKDIR /home/flask_app

COPY app.py /home/flask_app
COPY data_min.tsv /home/flask_app

RUN pip install numpy pandas flask
EXPOSE 5000
CMD python app.py --path data_min.tsv