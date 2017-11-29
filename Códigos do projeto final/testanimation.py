import pytumblr
# Authenticate via OAuth
client = pytumblr.TumblrRestClient(
  'consumer_key',
  'consumer_secret',
  'token',
  'token_secret'
)

# Make the request
client.info()

client.create_photo(
'AnimeDrink', 
state="published", 
tags=["raspberrypi", "picamera"], 
data="animation.gif"
)
print("uploaded")
