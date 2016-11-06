from django.conf.urls import patterns, include, url
from online import views
# Uncomment the next two lines to enable the admin:
from django.contrib import admin
admin.autodiscover();
urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'zhuce.views.home', name='home'),
    # url(r'^zhuce/', include('zhuce.foo.urls')),

    # Uncomment the admin/doc line below to enable admin documentation:
    # url(r'^admin/doc/', include('django.contrib.admindocs.urls')),

    # Uncomment the next line to enable the admin:
    url(r'^admin/', include(admin.site.urls)),
    url(r'^index/',views.index,name = 'reg'),
    url(r'^$',views.index,name = 'index'),
    url(r'^setpage/$',views.setpage,name = 'index'),                   
    url(r'^register/$',views.register,name = 'log'),
    url(r'^login/$',views.login_view,name = 'log'),
    url(r'^write/$',views.write_article,name = 'ri'),
    url(r'^logout/$',views.logout_view,name = 'ri'),
    url(r'^read.*/$',views.article_view,name = 'art'),
    url(r'^sessionset/$',views.sessionset,name = 'ri'),
    url(r'^edit.*/$',views.edit_art,name = 'art'),
    url(r'^syncdb/$',views.syncdb,name = 'art'),
    url(r'^about_me/$',views.about_me,name = 'art'),
    url(r'^comment_wall/$',views.comment_wall,name = 'art'),
    url(r'^set_comment/$',views.set_comment,name = 'art'),    
)
