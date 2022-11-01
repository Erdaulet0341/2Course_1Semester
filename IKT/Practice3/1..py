import requests as rq

headers = {'user-agent' : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/106.0.0.0 Safari/537.36'}
url = 'https://api.thedogapi.com/v1/breeds'
resp = rq.get(url, headers=headers)
resp_json = resp.json()
for i in resp_json:
    if(i['name'] == 'Boston Terrier'):
        print(i)