using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using SensorAPI.Models;
using Newtonsoft.Json;
using System.IO;

namespace SensorAPI.Controllers
{
    public class NodeMCUController : ApiController
    {
        string path = Directory.GetParent(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData)).FullName+"\\nodes.json";

        string FilePath = @"C:\nodes.json";

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
                // read json into object
                // file exisats
                if (!File.Exists(path))
                {
                    File.WriteAllText(path, String.Empty);
                }
                //convert json file to list
                List<NodeMCU> nodes = JsonConvert.DeserializeObject<List<NodeMCU>>(File.ReadAllText(path));

                //check if Json is already in List
                if (nodes != null)
                {
                    if (nodes.Contains(node))
                    {
                        // search for same IP in list (maybe change later)
                        nodes.First(n => n == node).Value = node.Value;
                    }
                    else // add it if not
                    {
                        nodes.Add(node);
                    }
                }
                // if list is null create new object and fill it 
                else
                {
                    nodes = new List<NodeMCU> { node };
                }
                // write file back
                File.WriteAllText(path, JsonConvert.SerializeObject(nodes));


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
