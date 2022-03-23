#!/bin/ruby
# -*- coding: utf-8 -*-
# cgi-printarg-ruby.cgi -- CGI プログラムに対する引数を表示するプログラム
# ~yas/syspro/www/cgi-printarg-ruby.cgi

require "cgi"

def main()
	@cgi = CGI.new()
	print_header()
	print_content()
	exit( 0 )
end

def print_header()
	printf("Content-Type: text/html\n")
	printf("\n")
end

def print_content()
	printf("<HTML><HEAD></HEAD><BODY><PRE>\n")
	printf("request_method: %s\n",e(@cgi.request_method))
	printf("script_name: %s\n",e(@cgi.script_name))
	printf("query_string: %s\n",e(@cgi.query_string))
	printf("content_length: %d\n",@cgi.content_length ? @cgi.content_length : 0 )
	qh = @cgi.keys
	i = 0
	qh.each { |name|
                val = @cgi[name]
                printf("qv[%d]: %s=%s \n",i,e(name),e(val) )
                i = i + 1
	}
	printf("</PRE></BODY></HTML>\n")
end

def e( str )
	return( str == nil ? "(null)" : CGI::escapeHTML(str) )
end

main()
