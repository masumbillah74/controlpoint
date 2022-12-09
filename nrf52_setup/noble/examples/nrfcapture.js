var events= require('events'); // becasue we are using the EventsEmitter pattern to emit events 
var util=require('util');

var noble = require('../index');

var debug=require('debug')('ble_Receiver'); // debug is on 
var _    =require('lodash'); // 


var bleReceiver= function()
{
  console.log('Creating a new gateway..');
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
			console.log('Started Scanning..');
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
	if(peripheral.address === "cc:9c:fa:c5:56:95")
	{
		var received_time= new Date().toISOString();
		var advertisement=peripheral.advertisement;
		var rssi = peripheral.rssi;
		var txPowerLevel = peripheral.txPowerLevel; 

		if (peripheral.advertisement.manufacturerData) 
		{
			
			var mqtt = require('mqtt')
			var client  = mqtt.connect('mqtt://localhost')
			 
			client.on('connect', function () 
			{

				 	client.publish('fromBLE', peripheral.advertisement.manufacturerData.toString('hex')+"");

			 
			})
		}	
	}

};

if (require.main===module)
{
  var blegateway= new bleReceiver();
  console.log('Module Started..');
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

