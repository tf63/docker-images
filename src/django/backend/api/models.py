from django.db import models

class Todo(models.Model):
    title = models.CharField(max_length=100, default="")

    def __str__(self):
        return f"{self.title}"