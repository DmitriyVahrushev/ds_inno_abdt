## С какой командой образ собирался
sudo docker build -t brat .

## C какой командой образ запускался
sudo docker run -d -p 8001:8001 -v /home/dmitriy/data_science_innoabdt/homework_2/ex2/data:/home/brat_app/brat-v1.3_Crunchy_Frog/data  brat
