from rest_framework import status
from rest_framework.views import APIView
from rest_framework.response import Response

from api.models import Todo
from api.serializers import TodoSerializer

class TodoAPIView(APIView):
    def get(self, request):
        try:
            # idの降順で最新の30件を取得
            queryset = Todo.objects.order_by("-id")[:30]
            serializer = TodoSerializer(queryset, many=True)

            return Response(serializer.data)
        except Exception as e:
            return Response(
                {"error": str(e)}, status=status.HTTP_500_INTERNAL_SERVER_ERROR
            )

    def post(self, request):
        data = request.data

        serializer = TodoSerializer(data=data)
        if serializer.is_valid():
            # Save the record
            record = serializer.save()
            return Response({"message": "Record created successfully."})
        else:
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)