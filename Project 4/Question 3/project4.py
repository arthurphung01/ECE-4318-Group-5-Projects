from Google import Create_Service
import base64
from tkinter import *
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

CLIENT_SECRET_FILE = 'credentials.json'
API_NAME = 'gmail'
API_VERSION = 'v1'
SCOPES = ['https://mail.google.com/']

service = Create_Service(CLIENT_SECRET_FILE, API_NAME, API_VERSION, SCOPES)

window = Tk()
window.title("Gmail Application")
window.geometry('700x500')

gmailLabel = Label(window, text='Send a message using Gmail API:', fg='black', font=('Times New Roman',15))
gmailLabel.grid(row=0, column=0, padx=5, pady=10)

recipient = StringVar()
sub = StringVar()
body = StringVar()

#Recipient of email
mailTo = Label(window, text='To: ', fg='black', font=('Times New Roman',12))
mailTo.grid(row=1, column=0, padx=0, pady=5)
mailTextTo = Entry(window, textvariable= recipient, fg='black', width='40', font=('Times New Roman',12))
mailTextTo.grid(row=1, column=1)

#Subject of email
mailSub = Label(window, text='Subject: ', fg='black', font=('Times New Roman',12))
mailSub.grid(row=2, column=0, padx=0, pady=5)
mailTextSub = Entry(window, textvariable= sub, fg='black', width='40', font=('Times New Roman',12))
mailTextSub.grid(row=2, column=1)

#Body of email
mailBody = Label(window, text='Body: ', fg='black', font=('Times New Roman',12))
mailBody.grid(row=3, column=0, padx=0, pady=5)
mailTextBody = Text(window, fg='black', font=('Times New Roman',12))
mailTextBody.place(x=70, y=150, width=575, height=250)

def send():
    emailMsg = mailTextBody.get("1.0", END)
    mimeMessage = MIMEMultipart()
    mimeMessage['to'] = mailTextTo.get()
    mimeMessage['subject'] = mailTextSub.get()
    mimeMessage.attach(MIMEText(emailMsg, 'plain'))
    raw_string = base64.urlsafe_b64encode(mimeMessage.as_bytes()).decode()

    message = service.users().messages().send(userId='me', body={'raw': raw_string}).execute()
    print(message)

#Send email
sendButton = Button(window, command = send, text='Send', fg='black', font=('Times New Roman',12))
sendButton.place(x=300, y=425, width=100)
window.mainloop()