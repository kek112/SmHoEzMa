using SensorAPI.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace SensorAPI.Controllers
{
    public class SmhoezmaController : ApiController
    {
        string path = Directory.GetParent(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData)).FullName + "\\nodes.json";
        // GET: api/Smhoezma
        public List<NodeMCU> Get()
        {
            //Return whole List of Objects which are currently saved in JSON String
            List<NodeMCU> nodes = Newtonsoft.Json.JsonConvert.DeserializeObject<List<NodeMCU>>(File.ReadAllText(path));

            return nodes;
        }

        // GET: api/Smhoezma/5
        public string Get(int id)
        {
            return "value";
        }

        // POST: api/Smhoezma
        public void Post([FromBody]string value)
        {
        }

        // PUT: api/Smhoezma/5
        public void Put(int id, [FromBody]string value)
        {
        }

        // DELETE: api/Smhoezma/5
        public void Delete(int id)
        {
        }
    }
}
