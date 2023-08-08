from django.urls import path
from api.views import TodoAPIView

app_name = "api"

urlpatterns = [
    path("todos", TodoAPIView.as_view(), name="todo")
]