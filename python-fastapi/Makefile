.PHONY: tests
tests:
	poetry run isort .
	poetry run autopep8 . --in-place --recursive
	poetry run pflake8 .
	poetry run mypy .
	poetry run pytest
