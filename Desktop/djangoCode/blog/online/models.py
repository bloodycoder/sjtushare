#coding:utf-8
from django.db import models

# Create your models here.
class User(models.Model):
    username = models.CharField(max_length=50)
    password = models.CharField(max_length=50)

    def __unicode__(self):
        return self.username

class Comment(models.Model):
    name = models.CharField(max_length = 20)
    content = models.CharField(max_length = 200)
    class Admin:
        list_display = ('name','content')
    class Meta:
        verbose_name_plural = "fuck"
    def __unicode__(self):
        return self.name
class Article(models.Model):
    title  =  models.CharField(max_length = 100)
    update_time  = models.DateTimeField()
    intro = models.CharField(max_length = 50)
    content = models.CharField(max_length = 8000)
    comments = models.ManyToManyField(Comment)
    def __unicode__(self):
        return self.title
    class Admin:
        list_display = ('title', 'update_time', 'intro')
class Aiticle_num(models.Model):
    number = models.IntegerField();

class Catogary(models.Model):
    title = models.CharField(max_length = 100,help_text = "cant show chinese huh")
    slug = models.SlugField(unique = True)
    description = models.TextField()
    class Meta:
        verbose_name_plural = "catogaries"
        ordering = ['title']
    class Admin:
        pass 
    def __unicode__(self):
        return self.title