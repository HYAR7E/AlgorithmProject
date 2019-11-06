# PROYECTO OPERATING SYSTEMS
## By HYAR7E

	Set up a web server
		Go to /var/www/html/ directory and store there your web files
		Create a apache config file in /etc/apache2/sites-available and duplicate the 000-default.conf file with the name of your site as mysite.com.conf
		Create a virtual host space for your pages and sub pages with your address
		You can get your ip address with 'ifconfig'
		'ServerName' and 'ServerAlias' are the names of our pages and we reach them by writing them in /etc/hosts file too
		We should indicate the root of our pages files in 'DocumentRoot'
		Afterwards we should active our page config file with 'sudo a2ensite mysite.com.conf'
		We gotta disable the default config too with 'sudo a2dissite 000-default.conf'
		Restart the apache service with 'sudo service apache2 restart'
		Make sure your address in config file and hosts file are the same
		Search in navigator's bar 'http://mysite.com'
		It should work!
