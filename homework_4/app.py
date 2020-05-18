from flask import Flask, render_template, jsonify, request, abort
import pandas as pd
import random

app = Flask(__name__)
movies = pd.read_csv("homework_4/data_min.tsv", sep="\t")

#возвращает пустой json файл при возникновении ошибки 404
@app.errorhandler(404)
def custom404(error):
    response = jsonify({})
    response.status_code = 404
    return response

@app.route("/movie_id/<movie_id>")
def get_movie_id(movie_id):
    result_movie = movies[movies['tconst'] == movie_id]
    if result_movie.empty:
        abort(404)
    result_movie = result_movie[['tconst', 'primaryTitle']].transpose()
    result_movie.columns = ['movie']
    result_movie.index = ['tconst', 'title']
    return result_movie.to_json()


@app.route("/movie/<title>")
def get_movie_title(title):
    result_movies = movies[(movies['primaryTitle'] == title) | (movies['originalTitle'] == title)]
    if result_movies.empty:
        abort(404)
    movies_list = result_movies['tconst'].tolist()
    return jsonify({'movies': movies_list})


@app.route("/year/<year>")
def get_movie_year(year):
    result_movies = movies[movies['startYear'] == int(year)]
    if result_movies.empty:
        abort(404)
    movies_list = result_movies['tconst'].tolist()
    return jsonify({'movies': movies_list})


@app.route("/suggest/<topk>", methods = ['POST'])
def post_movie_year(topk):
    recieved_json = request.get_json()
    likes = recieved_json["likes"] 
    k = len(likes)
    #убираем из списка фильмов уже оценённые фильмы
    possible_reccomends = movies[~movies['tconst'].isin(likes.keys())]
    #случайным образом выбираем фильмы для рекомендации  и оценки к ним
    recomends_titles = possible_reccomends['tconst'].sample(k).tolist()
    recomends_scores = [0.1*random.randint(0, 10) for i in range(k)]
    final_recomends = dict(zip(recomends_titles, recomends_scores))
    response = {"ratings": final_recomends} 
    return jsonify(response)


if __name__ == "__main__":
    app.run(debug=True)