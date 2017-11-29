import pytumblr
# Authenticate via OAuth
client = pytumblr.TumblrRestClient(
  'InGTzBWQBqk5uiWmYZ3tRNqj8mNJwoSWHLSMV4uWL9oYYj4AXY',
  'fFTOCT5Qd1pfNo4EdTsm2gdCFTfgW7mRpeesmhIYPV1acLOiJ7',
  'wgignLTrecixwckWLzVVZgL4ExXkG0VQQulyeVPYi6ZN54ED78',
  'i9rYOWXBPC1Y4t6nwqWmxC3SinlP4k7yHak7nWlkPTJveMOuin'
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
