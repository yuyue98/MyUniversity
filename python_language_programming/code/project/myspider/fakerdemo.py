import os
from faker import Faker
#os.system('pip list')
fake = Faker(locale='zh-CN')
a = fake.mac_platform_token()
# 'Macintosh; Intel Mac OS X 10_12_1'
fake.firefox()
# ('Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10_9_4; rv:1.9.4.20) '
#  'Gecko/2012-05-03 04:16:34 Firefox/3.6.10')
fake.windows_platform_token()
# 'Windows 95'
fake.safari()
# ('Mozilla/5.0 (iPod; U; CPU iPhone OS 3_1 like Mac OS X; sat-IN) '
#  'AppleWebKit/533.2.4 (KHTML, like Gecko) Version/3.0.5 Mobile/8B113 '
#  'Safari/6533.2.4')
fake.chrome(version_from=13, version_to=63, build_from=800, build_to=899)
# ('Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/5331 (KHTML, like Gecko) '
#  'Chrome/52.0.838.0 Safari/5331')
fake.opera()
# 'Opera/8.83.(X11; Linux i686; ce-RU) Presto/2.9.169 Version/10.00'
fake.mac_processor()
# 'Intel'
fake.user_agent()
# ('Mozilla/5.0 (Macintosh; Intel Mac OS X 10_7_9 rv:3.0; pa-IN) '
#  'AppleWebKit/532.47.6 (KHTML, like Gecko) Version/4.0.1 Safari/532.47.6')
fake.linux_platform_token()
# 'X11; Linux x86_64'
fake.linux_processor()
# 'i686'
fake.internet_explorer()
# 'Mozilla/5.0 (compatible; MSIE 5.0; Windows NT 5.01; Trident/3.1)'
print(a)