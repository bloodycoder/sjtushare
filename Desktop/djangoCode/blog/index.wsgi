import os
import django.core.handlers.wsgi
 
import sae
from sae.ext.shell import ShellMiddleware
 
os.environ['DJANGO_SETTINGS_MODULE'] = 'haha.settings'
 
#application = sae.create_wsgi_app(django.core.handlers.wsgi.WSGIHandler())
application = sae.create_wsgi_app(ShellMiddleware(django.core.handlers.wsgi.WSGIHandler()))
