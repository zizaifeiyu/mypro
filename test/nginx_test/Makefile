
build:
	$(MAKE) -f objs/Makefile

install:
	$(MAKE) -f objs/Makefile install

clean:
	rm -rf Makefile objs

upgrade:
	/usr/local/nginx/sbin/nginx -t

	kill -USR2 `cat /usr/local/nginx/logs/nginx.pid`
	sleep 1
	test -f /usr/local/nginx/logs/nginx.pid.oldbin

	kill -QUIT `cat /usr/local/nginx/logs/nginx.pid.oldbin`

upgrade1:
	# upgrade 0.1.x to 0.2+

	/usr/local/nginx/sbin/nginx -t

	cp /usr/local/nginx/logs/nginx.pid /usr/local/nginx/logs/nginx.pid.oldbin

	kill -USR2 `cat /usr/local/nginx/logs/nginx.pid`
	sleep 1
	test -f /usr/local/nginx/logs/nginx.pid.oldbin

	cp /usr/local/nginx/logs/nginx.pid /usr/local/nginx/logs/nginx.pid.newbin

	kill -QUIT `cat /usr/local/nginx/logs/nginx.pid.oldbin`
