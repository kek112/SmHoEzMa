using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using SensorAPI.Models;
using Newtonsoft.Json;


namespace SensorAPI.Controllers
{
    public class NodeMCUController : ApiController
    {
        // GET: api/NodeMCU
        public IEnumerable<string> Get()
        {
            return new string[] { "value1", "value2" };
        }

        // GET: api/NodeMCU/5
        public string Get(int id)
        {
            return "value";
        }

        // POST: api/NodeMCU
        public HttpResponseMessage Post([FromBody]NodeMCU node)
        {
            try
            {
                string json = JsonConvert.SerializeObject(node);
                





                var     message = Request.CreateResponse(HttpStatusCode.Created, node);
                        message.Headers.Location = new Uri(Request.RequestUri + node.SensorName.ToString());
                return  message;
            }
            catch(Exception ex)
            {
                return Request.CreateErrorResponse(HttpStatusCode.BadRequest, ex);
            }

        }

        // PUT: api/NodeMCU/5
        public void Put(int id, [FromBody]NodeMCU value)
        {
            
        }

        // DELETE: api/NodeMCU/5
        public void Delete(int id)
        {
        }
    }
}
