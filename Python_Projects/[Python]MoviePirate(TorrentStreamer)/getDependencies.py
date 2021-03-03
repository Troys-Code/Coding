import requests

# This function downloads Play file from web
def update():			
	url = "https://moviepirate.s3-us-west-1.amazonaws.com/play.py"
	file = requests.get(url)
	with open("play.py",'wb') as f:
		f.write(file.content)
