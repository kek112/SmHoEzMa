using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using SensorAPI.Models;

namespace SensorAPI.Controllers
{
    public class HumidityController : ApiController
    {


        // GET: api/Humidity
        public IEnumerable<string> Get()
        {
            return new string[] { "value1", "value2" };
        }

        // GET: api/Humidity/1
        public Humidity Get(int id)
        {
            if (1 == id)
            {
                Humidity HUMI = new Humidity();
                Stuff fkt = new Stuff();
                HUMI.HumidPerCent = fkt.GetRandomNumber(0, 100);
                HUMI.ModelName = "H-1000";

                return HUMI;
            }
            return null;

        }

        // POST: api/Humidity
        public void Post([FromBody]string value)
        {
        }

        // PUT: api/Humidity/5
        public void Put(int id, [FromBody]string value)
        {
        }

        // DELETE: api/Humidity/5
        public void Delete(int id)
        {
        }
    }
}
