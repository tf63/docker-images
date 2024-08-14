.PHONY: lint format test
lint:
	poetry run ruff check src
	poetry run mypy src

format:
	poetry run ruff format src
	poetry run ruff check --fix src

test:
	poetry run pytest
