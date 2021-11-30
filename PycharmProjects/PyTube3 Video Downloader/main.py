#PYTUBE3 IS NOT WORKING, SO WE GOTTA GO TO PYTUBEX
from pytube import YouTube

#Getting the LINK and sending to yt class:
link = input("Insira o link: ")
yt = YouTube(link)

#VIDEO INFORMATION:
print("Título: ", yt.title)
print("Views: ", yt.views)
print("Tamanho: ", yt.length)
print("Avaliação: ", yt.rating)

#OBTAINING THE VIDEO
#We can choose between PROGRESSIVE or DASH(audio and video separeted)
#print(yt.streams) -> it will show all the options
x = yt.streams.get_highest_resolution()

#DOWNLOAD
#EXAMPLE: abc.download("location")
print("Baixando...")
x.download()
