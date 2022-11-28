import Google 
import base64
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

CLIENT_SECRET_FILE = 'credentials.json'
API_NAME = 'gmail'
API_VERSION = 'v1'
SCOPES = ['https://mail.google.com/']

service = Google.create_service(CLIENT_SECRET_FILE, API_NAME, API_VERSION, SCOPES)

emailMsg = 'Resistance is futile. Just give up >:('
mimeMessage = MIMEMultipart()
mimeMessage['to'] = 'ece4318group5@gmail.com'
mimeMessage['cc'] = 'fabriciogalvan90@gmail.com'
mimeMessage['bcc'] = 'galvanprieto@cpp.edu'
mimeMessage['subject'] = 'Comply or else.'
mimeMessage.attach(MIMEText(emailMsg, 'plain'))
raw_string = base64.urlsafe_b64encode(mimeMessage.as_bytes()).decode()

message = service.users().messages().send(userId='me', body={'raw': raw_string}).execute()
print(message)
