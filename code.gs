function doPost(e) {
  var sheet = SpreadsheetApp.openById("<your-spreadsheet-id>").getSheetByName("<your-sheet-name>");
  
  try {
    var data = JSON.parse(e.postData.contents); 
    sheet.appendRow([new Date(), data.sensor1, data.sensor2, data.sensor3]);
    return ContentService.createTextOutput("Success").setMimeType(ContentService.MimeType.TEXT);
  } catch (error) {
    return ContentService.createTextOutput("Error: " + error).setMimeType(ContentService.MimeType.TEXT);
  }
}