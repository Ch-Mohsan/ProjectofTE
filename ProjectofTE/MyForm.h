#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
#include <stack>

namespace ProjectofTE {
    const int MAX_SIZE = 100; // Define a max size for the stack
    char globalArrayStack[MAX_SIZE]; // Global array to store characters
    int top = -1; // Global variable to track the top of the stack
    int currentPos = -1; // Current position in the stack

    std::stack<std::string> undoStack;
    std::stack<std::string> redoStack;

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ textIn;
        System::Windows::Forms::Button^ Submitted;
        System::Windows::Forms::Button^ Start;
        System::Windows::Forms::Button^ Next;
        System::Windows::Forms::Button^ Previous;
        System::Windows::Forms::Button^ End;
        System::Windows::Forms::Button^ Current;
        System::Windows::Forms::Button^ Undo;
        System::Windows::Forms::Button^ Redo;
        System::Windows::Forms::TextBox^ textB;
        System::Windows::Forms::TextBox^ textA;
    private: System::Windows::Forms::Button^ Insert;
    private: System::Windows::Forms::Button^ Delete;
    private: System::Windows::Forms::TextBox^ textE;
    private: System::Windows::Forms::Label^ label1;



    private: System::Windows::Forms::Label^ label5;

    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label8;






    protected:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->textIn = (gcnew System::Windows::Forms::TextBox());
            this->Submitted = (gcnew System::Windows::Forms::Button());
            this->Start = (gcnew System::Windows::Forms::Button());
            this->Next = (gcnew System::Windows::Forms::Button());
            this->Previous = (gcnew System::Windows::Forms::Button());
            this->End = (gcnew System::Windows::Forms::Button());
            this->Current = (gcnew System::Windows::Forms::Button());
            this->Undo = (gcnew System::Windows::Forms::Button());
            this->Redo = (gcnew System::Windows::Forms::Button());
            this->textB = (gcnew System::Windows::Forms::TextBox());
            this->textA = (gcnew System::Windows::Forms::TextBox());
            this->Insert = (gcnew System::Windows::Forms::Button());
            this->Delete = (gcnew System::Windows::Forms::Button());
            this->textE = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // textIn
            // 
            this->textIn->Location = System::Drawing::Point(381, 63);
            this->textIn->Name = L"textIn";
            this->textIn->Size = System::Drawing::Size(284, 20);
            this->textIn->TabIndex = 0;
            // 
            // Submitted
            // 
            this->Submitted->ForeColor = System::Drawing::Color::MediumAquamarine;
            this->Submitted->Location = System::Drawing::Point(729, 63);
            this->Submitted->Name = L"Submitted";
            this->Submitted->Size = System::Drawing::Size(255, 23);
            this->Submitted->TabIndex = 1;
            this->Submitted->Text = L"Submit";
            this->Submitted->UseVisualStyleBackColor = true;
            this->Submitted->Click += gcnew System::EventHandler(this, &MyForm::Submitted_Click);
            // 
            // Start
            // 
            this->Start->Location = System::Drawing::Point(34, 75);
            this->Start->Name = L"Start";
            this->Start->Size = System::Drawing::Size(267, 23);
            this->Start->TabIndex = 2;
            this->Start->Text = L"Move to Start";
            this->Start->UseVisualStyleBackColor = true;
            this->Start->Click += gcnew System::EventHandler(this, &MyForm::Start_Click);
            // 
            // Next
            // 
            this->Next->Location = System::Drawing::Point(34, 124);
            this->Next->Name = L"Next";
            this->Next->Size = System::Drawing::Size(267, 23);
            this->Next->TabIndex = 3;
            this->Next->Text = L"Move to Next";
            this->Next->UseVisualStyleBackColor = true;
            this->Next->Click += gcnew System::EventHandler(this, &MyForm::Next_Click);
            // 
            // Previous
            // 
            this->Previous->Location = System::Drawing::Point(34, 170);
            this->Previous->Name = L"Previous";
            this->Previous->Size = System::Drawing::Size(267, 23);
            this->Previous->TabIndex = 4;
            this->Previous->Text = L"Move to Previous";
            this->Previous->UseVisualStyleBackColor = true;
            this->Previous->Click += gcnew System::EventHandler(this, &MyForm::Previous_Click);
            // 
            // End
            // 
            this->End->Location = System::Drawing::Point(34, 225);
            this->End->Name = L"End";
            this->End->Size = System::Drawing::Size(267, 23);
            this->End->TabIndex = 5;
            this->End->Text = L"Move to End";
            this->End->UseVisualStyleBackColor = true;
            this->End->Click += gcnew System::EventHandler(this, &MyForm::End_Click);
            // 
            // Current
            // 
            this->Current->Location = System::Drawing::Point(34, 284);
            this->Current->Name = L"Current";
            this->Current->Size = System::Drawing::Size(267, 23);
            this->Current->TabIndex = 6;
            this->Current->Text = L"Current Position";
            this->Current->UseVisualStyleBackColor = true;
            this->Current->Click += gcnew System::EventHandler(this, &MyForm::Current_Click);
            // 
            // Undo
            // 
            this->Undo->ForeColor = System::Drawing::Color::Green;
            this->Undo->Location = System::Drawing::Point(299, 395);
            this->Undo->Name = L"Undo";
            this->Undo->Size = System::Drawing::Size(252, 23);
            this->Undo->TabIndex = 7;
            this->Undo->Text = L"Undo";
            this->Undo->UseVisualStyleBackColor = true;
            this->Undo->Click += gcnew System::EventHandler(this, &MyForm::Undo_Click);
            // 
            // Redo
            // 
            this->Redo->ForeColor = System::Drawing::Color::Red;
            this->Redo->Location = System::Drawing::Point(609, 392);
            this->Redo->Name = L"Redo";
            this->Redo->Size = System::Drawing::Size(248, 23);
            this->Redo->TabIndex = 8;
            this->Redo->Text = L"Redo";
            this->Redo->UseVisualStyleBackColor = true;
            this->Redo->Click += gcnew System::EventHandler(this, &MyForm::Redo_Click);
            // 
            // textB
            // 
            this->textB->Location = System::Drawing::Point(381, 127);
            this->textB->Name = L"textB";
            this->textB->Size = System::Drawing::Size(284, 20);
            this->textB->TabIndex = 9;
            textB->Enabled = false;
            // 
            // textA
            // 
            this->textA->Location = System::Drawing::Point(381, 205);
            this->textA->Name = L"textA";
            this->textA->Size = System::Drawing::Size(284, 20);
            this->textA->TabIndex = 10;
            textA->Enabled = false;
            // 
            // Insert
            // 
            this->Insert->ForeColor = System::Drawing::Color::Green;
            this->Insert->Location = System::Drawing::Point(299, 339);
            this->Insert->Name = L"Insert";
            this->Insert->Size = System::Drawing::Size(252, 23);
            this->Insert->TabIndex = 11;
            this->Insert->Text = L"Insert";
            this->Insert->UseVisualStyleBackColor = true;
            this->Insert->Click += gcnew System::EventHandler(this, &MyForm::Insert_Click);
            // 
            // Delete
            // 
            this->Delete->ForeColor = System::Drawing::Color::Red;
            this->Delete->Location = System::Drawing::Point(609, 339);
            this->Delete->Name = L"Delete";
            this->Delete->Size = System::Drawing::Size(248, 23);
            this->Delete->TabIndex = 12;
            this->Delete->Text = L"Delete";
            this->Delete->UseVisualStyleBackColor = true;
            this->Delete->Click += gcnew System::EventHandler(this, &MyForm::Delete_Click);
            // 
            // textE
            // 
            this->textE->Location = System::Drawing::Point(381, 284);
            this->textE->Name = L"textE";
            this->textE->Size = System::Drawing::Size(284, 20);
            this->textE->TabIndex = 13;
            this->textE->TextChanged += gcnew System::EventHandler(this, &MyForm::textE_TextChanged);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(378, 268);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(99, 13);
            this->label1->TabIndex = 14;
            this->label1->Text = L"Edit Your New Text";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(378, 47);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(81, 13);
            this->label5->TabIndex = 18;
            this->label5->Text = L"Enter Your Text";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(385, 111);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(53, 13);
            this->label7->TabIndex = 20;
            this->label7->Text = L"Your Text";
            this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(378, 190);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(64, 13);
            this->label8->TabIndex = 21;
            this->label8->Text = L"Your Output";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1109, 749);
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            this->Controls->Add(this->label8);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textE);
            this->Controls->Add(this->Delete);
            this->Controls->Add(this->Insert);
            this->Controls->Add(this->textA);
            this->Controls->Add(this->textB);
            this->Controls->Add(this->Redo);
            this->Controls->Add(this->Undo);
            this->Controls->Add(this->Current);
            this->Controls->Add(this->End);
            this->Controls->Add(this->Previous);
            this->Controls->Add(this->Next);
            this->Controls->Add(this->Start);
            this->Controls->Add(this->Submitted);
            this->Controls->Add(this->textIn);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void Start_Click(System::Object^ sender, System::EventArgs^ e) {
        if (top >= 0) {
            currentPos = 0;
            ShowCurrentCharacter();
        }
    }

    private: System::Void Next_Click(System::Object^ sender, System::EventArgs^ e) {
        if (currentPos < top) {
            currentPos++;
            ShowCurrentCharacter();
        }
    }

    private: System::Void Previous_Click(System::Object^ sender, System::EventArgs^ e) {
        if (currentPos > 0) {
            currentPos--;
            ShowCurrentCharacter();
        }
    }

    private: System::Void End_Click(System::Object^ sender, System::EventArgs^ e) {
        if (top >= 0) {
            currentPos = top;
            ShowCurrentCharacter();
        }
    }

    private: System::Void Current_Click(System::Object^ sender, System::EventArgs^ e) {
        if (currentPos >= 0 && currentPos <= top) {
            UpdateTextA();
        }
    }

    private: System::Void Submitted_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ inputText = textIn->Text; // Read input from textIn TextBox
        std::string inputStr = msclr::interop::marshal_as<std::string>(inputText); // Convert System::String^ to std::string

        // Initialize the top index of the stack
        top = -1;
        currentPos = -1;

        // Clear undo and redo stacks
        while (!undoStack.empty()) undoStack.pop();
        while (!redoStack.empty()) redoStack.pop();

        // Push characters to the array stack
        for (char ch : inputStr)
        {
            if (top < MAX_SIZE - 1) {
                globalArrayStack[++top] = ch;
            }
        }

        // Create a string to store the output for textB
        std::string output;
        for (int i = 0; i <= top; ++i) {
            output += globalArrayStack[i];
        }

        // Display the output in textB
        textB->Text = gcnew String(output.c_str());

        // Display the first character in textA
        if (top >= 0) {
            currentPos = 0;
            // UpdateTextA();
        }
    }

  
 private: System::Void Insert_Click(System::Object^ sender, System::EventArgs^ e) {
     // Get the character to insert from textE textbox
     String^ insertChar = textE->Text;

     // Convert System::String^ to std::string
     std::string insertStr = msclr::interop::marshal_as<std::string>(insertChar);

     // Check if current position is within bounds
     if (currentPos >= 0 && currentPos <= top && top < MAX_SIZE - 1) {
         // Push the current state onto the undo stack
         undoStack.push(msclr::interop::marshal_as<std::string>(textB->Text));

         // Shift elements to make space for the new character
         for (int i = top + 1; i > currentPos; --i) {
             globalArrayStack[i] = globalArrayStack[i - 1];
         }

         // Insert the character at the current position
         globalArrayStack[currentPos] = insertStr[0];
         top++; // Increment top

         // Update textB to show the complete string
         UpdateTextB();
     }
 }

private: System::Void Delete_Click(System::Object^ sender, System::EventArgs^ e) {
    // Check if current position is within bounds
    if (currentPos >= 0 && currentPos <= top) {
        // Push the current state onto the undo stack
        undoStack.push(msclr::interop::marshal_as<std::string>(textB->Text));

        // Shift elements to overwrite the character at the current position
        for (int i = currentPos; i < top; ++i) {
            globalArrayStack[i] = globalArrayStack[i + 1];
        }

        top--; // Decrement top

        // Update textB to show the complete string
        UpdateTextB();
    }
}

private: void UpdateTextB() {
    // Create a string to store the complete string
    std::string output;
    for (int i = 0; i <= top; ++i) {
        output += globalArrayStack[i];
    }

    // Display the complete string in textB
    textB->Text = gcnew String(output.c_str());
}

private: System::Void textE_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

 private: System::Void Undo_Click(System::Object^ sender, System::EventArgs^ e) {
     if (!undoStack.empty()) {
         // Push the current state onto the redo stack
         redoStack.push(msclr::interop::marshal_as<std::string>(textB->Text));

         // Pop the top state from the undo stack and revert the change
         std::string lastState = undoStack.top();
         undoStack.pop();
         textB->Text = gcnew String(lastState.c_str());
     }
 }

private: System::Void Redo_Click(System::Object^ sender, System::EventArgs^ e) {
    if (!redoStack.empty()) {
        // Push the current state onto the undo stack
        undoStack.push(msclr::interop::marshal_as<std::string>(textB->Text));

        // Pop the top state from the redo stack and reapply the change
        std::string nextState = redoStack.top();
        redoStack.pop();
        textB->Text = gcnew String(nextState.c_str());
    }
}

    private: void UpdateTextA() {
        if (currentPos >= 0 && currentPos <= top) {
            std::string output(1, globalArrayStack[currentPos]);
            textA->Text = gcnew String(output.c_str());
        }
    }

    private: void ShowCurrentCharacter() {
        if (currentPos >= 0 && currentPos <= top) {
            std::string output(1, globalArrayStack[currentPos]);
            textA->Text = gcnew String(output.c_str());
            Console::WriteLine("Current position: " + currentPos + " character: " + textA->Text);
        }
    }



private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}