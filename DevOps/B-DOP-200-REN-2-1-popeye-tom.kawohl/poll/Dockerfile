FROM python:3
WORKDIR /app
COPY . /app
RUN pip install --no-cache-dir -r requirements.txt
ENV FLASK_APP=app.py
EXPOSE 80
CMD ["flask", "run", "--host=0.0.0.0", "--port=80"]