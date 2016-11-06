from django.contrib import admin
from online.models import Comment,Catogary

class CommentAdmin(admin.ModelAdmin):
    pass
class CatogaryAdmin(admin.ModelAdmin):
    pass
admin.site.register(Catogary,CommentAdmin)
admin.site.register(Comment, CommentAdmin)