.PHONY: lint format test
lint:
	ruff check src
	mypy src

format:
	ruff format src
	ruff check --fix src

test:
	pytest
