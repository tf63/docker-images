#!/bin/sh
python manage.py makemigrations api
python manage.py migrate --noinput
# python manage.py collectstatic --noinput
# python manage.py loaddata api/fixtures/*.json

if [ $DEBUG = 1 ]; then
    python manage.py runserver 0.0.0.0:8000
elif [ $DEBUG = 0 ]; then
    gunicorn backend.wsgi:application --bind 0.0.0.0:8000
fi
