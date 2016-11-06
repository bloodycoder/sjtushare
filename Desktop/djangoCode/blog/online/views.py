# Create your views here.
#coding=utf-8
from django.shortcuts import render,render_to_response
from django.http import HttpResponse,HttpResponseRedirect
from django.template import RequestContext
from django import forms
from django.contrib.auth.models import User
from online import models
from django.contrib.auth import authenticate,login,logout
from datetime import datetime
import sys
import StringIO
#表单
def index(request):
    article_num = models.Aiticle_num.objects.all()[0].number;
    if(not('current_page' in request.session)):
        request.session['current_page'] = '1'
    current_page = int(request.session["current_page"])
    if(article_num%6==0):
        all_pages = article_num/6
    else:
        all_pages = article_num/6+1
        
    if(current_page%5==0):
        first_page = current_page -4;
    else:
        first_page =  5*((current_page)/5)+1   
    light_on = [0,0,0,0,0]
    light_on[(current_page % 5)-1] = 1
    pages_below = [first_page]
    for i in range(1,5):
        if(first_page+i<=all_pages):
            pages_below.append(first_page+i)
        else:
            pages_below.append(0)
    #show the article 
    all_articles = models.Article.objects.order_by("-update_time")
    first_article = 6*(current_page-1)
    if(first_article+5<= article_num-1):
        pages_to_show = all_articles[first_article:first_article+6]
    else:
        pages_to_show = all_articles[first_article:]
    below_pages = list()
    for page in pages_to_show:
        below_pages.append(page)
    while(len(below_pages)<=6):
        below_pages.append(0)
    return render_to_response('index.htm',{'login_view':request.user.is_authenticated(),'current_page':0,'top_article':\
    pages_to_show[0],'article1':below_pages[1],'article2':below_pages[2],\
   'article3':below_pages[3],'article4':below_pages[4],\
    'article5':below_pages[5],'first':pages_below[0] ,'second':pages_below[1],\
    'third':pages_below[2],'fourth':pages_below[3],'fifth':pages_below[4],'on1':light_on[0],'on2':light_on[1],'on3':light_on[2],'on4':light_on[3],'on5':light_on[4]})

def setpage(request):
    a = request.GET['page']
    if(a == 'plus/'):
        article_num = models.Aiticle_num.objects.all()[0].number;
        if(article_num%6==0):
            all_pages = article_num/6
        else:
            all_pages = article_num/6+1
        page = int(request.session['current_page'])
        if(page<all_pages):
            page +=1;
        request.session['current_page'] = str(page)
    elif(a=='minus/'):
        page = int(request.session['current_page'])
        if(page>1):
            page -=1;
        request.session['current_page'] = page
    else:
        request.session['current_page'] = a;
    return HttpResponseRedirect('/index/')

def register(request):
    user = User.objects.create_user(username = "picard",password = "992288");
    user.save();
    return HttpResponse('success!');
def login_view(request):
    errors = []
    if request.method == 'POST':
        username1 = request.POST.get('username','')
        password1 = request.POST.get('password1','')
        user = authenticate(username = username1,password = password1)
        if user is not None:
            login(request,user)
            return HttpResponseRedirect('/index/')
        else:
            errors.append('密码错误')
            return render_to_response('login.html',{'errors':errors},context_instance=RequestContext(request));

    else:
        return render_to_response('login.html',{'errors':errors},context_instance=RequestContext(request));

def write_article(request):
    if(not request.user.is_authenticated()):
        return HttpResponse('sorry,please login')
    if request.method == 'POST':
        title = request.POST.get('title','')
        contents = request.POST.get('contents','')
        art1 = models.Article()
        art1.title = title
        art1.update_time = datetime.now()
        art1.content = contents
        if(len(contents)>=50):
            art1.intro = contents[0:49]
        else:
            art1.intro = contents
        art1.save()
        t1 = models.Aiticle_num.objects.all()[0]
        t1.number +=1
        t1.save()
        return HttpResponseRedirect('/index/')
    else:
        return render_to_response('write.htm',context_instance=RequestContext(request))

def logout_view(request):
    logout(request)
    return HttpResponse('logout success~!')

def article_view(request):
    art_id = str(request.GET['page'])
    if(art_id[-1]=='/'):
        art_id = art_id[0:-1]
    art_id = int(art_id)
    article = models.Article.objects.get(id = art_id)
    now = article.update_time
    update_date = str(now.year)+'-'+str(now.month)+'-'+str(now.day)+'  '+str((now.hour+8)%24)+':';
    if(now.minute<10):
        update_date += '0'+str(now.minute)+':'
    else:
        update_date += str(now.minute)+':'
    if(now.second<10):
        update_date += '0'+str(now.second)
    else:
        update_date += str(now.second)
    return render_to_response('blog_content.htm',{'article':article,'datetime':update_date,'login_view':request.user.is_authenticated()},context_instance=RequestContext(request))

def sessionset(request):
    request.session['current_page'] = '1'
    return HttpResponseRedirect('/index/')
def edit_art(request):
    if(request.method=='POST'):
        art_id = request.POST.get('id','')
        content = request.POST.get('content','')
        title = request.POST.get('title','')
        article = models.Article.objects.get(id = art_id)
        article.content = content
        article.title = title
        if(len(content)>=50):
            article.intro = content[0:49]
        else:
            article.intro = content
        article.save()
        return HttpResponseRedirect('/index/')
    else:
        art_id = request.GET['art_id']
        article = models.Article.objects.get(id = art_id)
        return render_to_response('edit.htm',{'title':article.title,'id':article.id,'content':article.content},context_instance=RequestContext(request))
def syncdb(request):
    #重定向标准输出重定向到内存的字符串缓冲(由StringIO模块提供)
    saveout = sys.stdout
    log_out = StringIO.StringIO()  
    sys.stdout = log_out 
    #利用django提供的命令行工具来执行“manage.py syncdb”
    from django.core.management import execute_from_command_line
    execute_from_command_line(["manage.py", "syncdb", "--noinput"])
    #获得“manage.py syncdb”的执行输出结果，并展示在页面
    result = log_out.getvalue()
    sys.stdout = saveout
    article_num = models.Aiticle_num()
    article_num.number = 0;
    article_num.save()
    return HttpResponse(result.replace("/n","<br/>")) 

def about_me(request):
    return render_to_response('about_me.htm');
def set_comment(request):
    com = models.Aiticle_num()
    com.number = 0;
    com.save()
    return HttpResponse('success')
def comment_wall(request):
    #获得该页应该显示的那几个实例并显示出来
    if(request.method =='POST'):
        name = request.POST.get('name','')
        content = request.POST.get('content','')
        if(len(name)>=1 and len(content)>=2):
            comment = models.Comment()
            comment.name = name;
            comment.content = content;
            comments_num = models.Aiticle_num.objects.all()[1]
            comments_num.number = comments_num.number+1
            comments_num.save()
            comment.save()
            return HttpResponseRedirect('/comment_wall/?page=1/')
        else:
            return render_to_response('errorpage.htm');
    else:
        all_comments = models.Comment.objects.order_by("-id")
        comments_num = models.Aiticle_num.objects.all()[1].number
        page = request.GET['page']
        if(page[-1]=='/'):
            page = int(page[:-1])
        #先获得实例
        first_comment = 6*(page-1)
        if(first_comment>comments_num-1):
            return render_to_response('comment_wall.htm',{'prepage':1,'nextpage':1,'currentpage':1,'com1':0,'com2':0,'com3':0,'com4':0,'com5':0,'com6':0,'page1':0,'page2':0,'page3':0,'page4':0,'page5':0},context_instance=RequestContext(request));
        
        if(first_comment+5>comments_num-1):
            comments_to_show =  all_comments[first_comment:]
        else:
            comments_to_show = all_comments[first_comment:first_comment+6];
        comments_list = list()
        for item in comments_to_show:
            comments_list.append(item)
        while(len(comments_list)<6):
            comments_list.append(0)
        #再获得第一页和后几页。
        all_pages=[]
        if(page%5==0):
            all_pages.append(page-4)
        else:
            all_pages.append(5*(page/5)+1)
        for i in range(1,5):
            all_pages.append(all_pages[0]+i)
            if((all_pages[-1]-1)*6>comments_num-1):
                all_pages[-1] = 0
        if(page>=2):
            prepage = page-1;
        else:
            prepage = 1;
        if(page*6>comments_num-1):
            nextpage = page;
        else:
            nextpage = page+1;
        return render_to_response('comment_wall.htm',{'prepage':prepage,'nextpage':nextpage,'currentpage':page,'com1':comments_list[0],\
'com2':comments_list[1],'com3':comments_list[2],'com4':comments_list[3],\
'com5':comments_list[4],'com6':comments_list[5],'page1':all_pages[0],\
'page2':all_pages[1],'page3':all_pages[2],'page4':all_pages[3],\
'page5':all_pages[4]                         },context_instance=RequestContext(request));
    
