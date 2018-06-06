using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using SensorAPI.Models;


namespace SensorAPI.Controllers
{
    public class TemperatureController : ApiController
    {
        // GET: api/Thermo
        public IEnumerable<string> Get()
        {
            return new string[] { "value1", "value2" };
        }

        // GET: api/Thermo/1
        public Temperature Get(int id)
        {

            /*
             * Thermo/1 --> gibt temperatur wieder
             * 
             * 
             */
            if (1 == id)
            {
                Temperature Thermometer = new Temperature();
                Stuff fkt = new Stuff();
                Thermometer.Celsius = fkt.GetRandomNumber(-30, 30);
                Thermometer.ModelName = "T-1000";

                return Thermometer;
            }
            return null;
        }

        // POST: api/Thermo
        public void Post([FromBody]string value)
        {
        }

        // PUT: api/Thermo/5
        public void Put(int id, [FromBody]string value)
        {
        }

        // DELETE: api/Thermo/5
        public void Delete(int id)
        {
        }
    }
}
