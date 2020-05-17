from flask import Flask, render_template, jsonify, request

app = Flask(__name__)



@app.route("/movie_id/<movie_id>")
def get_movie_id(movie_id):
    return 

if __name__ == "__main__":
    app.run()