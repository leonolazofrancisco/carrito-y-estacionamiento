require 'twitter'
require 'serialport'
require 'rubygems'

#params for serial port
port_str = "/dev/ttyACM7"  #may be different for you
baud_rate = 9600
data_bits = 8
stop_bits = 1
parity = SerialPort::NONE
mensaje=""
sp = SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)

#params for twitter
client = Twitter::REST::Client.new do |config|
      config.consumer_key = 'lf2DgqW2BUHgWw20u23QXTfal'
      config.consumer_secret = 'JKpIxRJLqjZcpKaznyuPZzgcYTMyrXjDJWmh3kQG68N0wOTR9w'
      config.oauth_token = '34119864-qd1UIjmEjxV2FmkFCYrV9oltHzP4LffFETvaAlsCj'
      config.oauth_token_secret = '22ipatOh1IxB2G7reEkBDoROKxhULsyBMdtA8cUute44a'
    end
#client.update(var)
while true do
  while (i=sp.gets)do
	puts i
       client.update("Lugares Disponibles: "+i)
end
end
sp.close



