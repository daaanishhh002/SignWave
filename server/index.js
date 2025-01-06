import express from "express";
import { WebSocketServer } from "ws";
import os from "os";
import fs from "fs";
import { createObjectCsvWriter } from "csv-writer";  // Import csv-writer

const app = express();
const port = 8080;

// Function to get local IP address
function getLocalIPAddress() {
    const interfaces = os.networkInterfaces();
    for (const interfaceName in interfaces) {
        for (const iface of interfaces[interfaceName]) {
            if (iface.family === "IPv4" && !iface.internal) {
                return iface.address;
            }
        }
    }
    return "127.0.0.1"; // Fallback to localhost
}

const server = app.listen(port, () => {
    const serverIP = getLocalIPAddress();
    console.log(`Server is listening on http://${serverIP}:${port}`);
});

// Create a CSV writer instance
const csvWriter = createObjectCsvWriter({
    path: "data.csv", // CSV file path
    header: [
        { id: "left1", title: "left1" },
        { id: "left2", title: "left2" },
        { id: "left3", title: "left3" },
        { id: "left4", title: "left4" },
        { id: "left5", title: "left5" },
        { id: "right1", title: "right1" },
        { id: "right2", title: "right2" },
        { id: "right3", title: "right3" },
        { id: "right4", title: "right4" },
        { id: "right5", title: "right5" },
        { id: "right_ax", title: "right_ax" },
        { id: "right_ay", title: "right_ay" },
        { id: "right_az", title: "right_az" },
        { id: "right_gx", title: "right_gx" },
        { id: "right_gy", title: "right_gy" },
        { id: "right_gz", title: "right_gz" }
    ],
    append: true, // Append to CSV instead of overwriting
});

const wss = new WebSocketServer({ server });

wss.on("connection", (ws, req) => {
    const clientIP = req.socket.remoteAddress;
    console.log(`New WebSocket connection from: ${clientIP}`);

    ws.on("message", (data) => {
        try {
            const jsonData = JSON.parse(data);
            console.log("Received JSON data:", jsonData);

            // Save the data to CSV
            csvWriter.writeRecords([jsonData])  // Write data as a new row in CSV
                .then(() => {
                    console.log("Data saved to data.csv");
                    ws.send("Data received and saved!");
                })
                .catch((err) => {
                    console.error("Error saving data:", err);
                    ws.send("Error saving data");
                });
        } catch (error) {
            console.error("Invalid JSON received:", data);
            ws.send("Invalid JSON format");
        }
    });

    ws.on("close", () => {
        console.log(`WebSocket client ${clientIP} disconnected.`);
    });
});
