## Пример пост запроса и возвращаемый результат
![example_request](post_example.png)
## Работа с контейнером
### Сборка образа
<p><code>sudo docker build -t flask_app .</code></p>
### Запуск контейнера
<p><code>sudo docker run -d -p 5412:5000 flask_app .</code></p>
![example_docker](example2.png)