## С какой командой образ собирался
sudo docker build -t brat .

## Пример запуска контейнера
sudo docker run -d -p 8001:8001 -v /home/dmitriy/data_science_innoabdt/homework_2/ex2/data:/home/brat_app/brat-v1.3_Crunchy_Frog/data  brat

![alt-text](https://github.com/DmitriyVahrushev/ds_inno_abdt/blob/master/homework_2/ex2/brat_is_working_screen.png)
