import quandl
quandl.ApiConfig.api_key = "5iYGy79Ma3RfVzyf4zKr"
data = quandl.get_table('MER/F1', compnumber="39102", paginate=True)
print(data)