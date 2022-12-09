var events= require('events'); // becasue we are using the EventsEmitter pattern to emit events 
var util=require('util');

var noble = require('../index');

var debug=require('debug')('ble_Receiver'); // debug is on 
var _    =require('lodash'); // 


var bleReceiver= function()
{
  debug('Creating a new gateway..');
  noble.on('discover', this.on_discover.bind(this));
  noble.on('scanstop', this.on_scanstop.bind(this));

};

util.inherits(bleReceiver,events.EventEmitter);

bleReceiver.prototype.start = function()
{

  debug('starting noble...');
  var startScanningPowerOn= function()
  {
    if (noble.state=== 'poweredOn')
		{
      noble.startScanning([],true);
    } 
		else
		{
      noble.once('stateChange', startScanningPowerOn);
    }
  };
  startScanningPowerOn();
};


bleReceiver.prototype.on_scanstop= function()
{
  noble.startScanning([],true);

};

bleReceiver.prototype.on_discover= function(peripheral)
{
	//if(peripheral.advertisement.localName === "Smart Socket")
	if(peripheral.address === "b4:99:4c:52:b9:dc")	
	{

		var received_time= new Date().toISOString();
		var advertisement=peripheral.advertisement;
		var rssi = peripheral.rssi;
		var txPowerLevel = peripheral.txPowerLevel; 

		debug('inside on_discover..');

		if (peripheral.advertisement.manufacturerData) 
		{
			var cur = JSON.stringify(peripheral.advertisement.manufacturerData.toString('hex'));
	  
			var status = cur[0];
      var power_factor = cur[1];
      var current_decimal_point_value = (cur[2] & 0xC0) >> 6;
      var wattage_decimal_point_value = (cur[2] & 0x30) >> 4;
      var voltage = (((cur[2] & 0x0F) << 8) + cur[3])/10;
      var current_value = (((cur[4] >> 4) & 0xF)*1000 +(cur[4] & 0xF)*100 + ((cur[5] >> 4) & 0xF)*10 + (cur[5] & 0xF));
      var wattage_value = (((cur[6] >> 4) & 0xF)*1000 + (cur[6] & 0xF)*100 + ((cur[7] >> 4) & 0xF)*10 +(cur[7] & 0xF)); 

			//console.log("Current: " + current_value + "\nVoltage "+ voltage+ "\nWattage " + wattage_value);

			var mqtt = require('mqtt')
			var client  = mqtt.connect('mqtt://localhost')
			 
			client.on('connect', function () 
			{
				 	client.publish('fromSocket', voltage+"");
			})	

		}	
	}
};

if (require.main===module)
{
  var blegateway= new bleReceiver();
  //console.log('Module Started..');

	blegateway.on('advertisement',function(adv_obj) 
	{
		console.log(adv_obj);

  });
  blegateway.start();
}
else 
{
  module.exports = new bleReceiver();
}

