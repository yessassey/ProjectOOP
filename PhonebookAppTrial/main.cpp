#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include <stdio.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <cstring>

#include "Person.h"
#include "PhonebookManager.h"
#include "IContactManager.h"

using namespace std;

static void glfw_error_callback(int error, const char *description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main(int, char **)
{
    IContactManager *manager = new PhonebookManager();

    int selectedIndex = -1;
    int scrollToIndex = -1;
    bool isAddingNew = true;

    array<char, 256> nameBuf = {0};
    array<char, 256> nickBuf = {0};
    array<char, 256> phoneBuf = {0};
    array<char, 256> emailBuf = {0};
    array<char, 256> addrBuf = {0};
    array<char, 128> searchBuf = {0};

    bool showAddedPopup = false;
    bool showUpdatedPopup = false;
    bool showDeletedPopup = false;

    // glfw + imgui setup
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow *window = glfwCreateWindow(1000, 600, "Phonebook - ImGui", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui::StyleColorsDark();
    io.Fonts->AddFontDefault();
    io.FontGlobalScale = 1.6f;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // loop - main
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Phonebook");

        // ========== TOP BUTTON BAR ==========
        ImGui::BeginGroup();

        ImGui::InputText("##search", searchBuf.data(), searchBuf.size());
        auto doSearch = [&]()
        {
            string key = searchBuf.data();
            if (key.empty())
                return;

            auto &contacts = manager->getContacts();
            for (int i = 0; i < (int)contacts.size(); i++)
            {
                if (contacts[i].getName().find(key) != string::npos ||
                    contacts[i].getNickname().find(key) != string::npos ||
                    contacts[i].getPhone().find(key) != string::npos ||
                    contacts[i].getEmail().find(key) != string::npos)
                {
                    selectedIndex = i;
                    scrollToIndex = i;
                    isAddingNew = false;

                    strcpy(nameBuf.data(), contacts[i].getName().c_str());
                    strcpy(nickBuf.data(), contacts[i].getNickname().c_str());
                    strcpy(phoneBuf.data(), contacts[i].getPhone().c_str());
                    strcpy(emailBuf.data(), contacts[i].getEmail().c_str());
                    strcpy(addrBuf.data(), contacts[i].getAddress().c_str());
                    break;
                }
            }
        };

        if (ImGui::IsItemDeactivatedAfterEdit())
            doSearch();
        ImGui::SameLine();
        if (ImGui::Button("Search"))
            doSearch();
        ImGui::SameLine();
        if (ImGui::Button("Clear"))
        {
            memset(searchBuf.data(), 0, searchBuf.size());
            selectedIndex = -1;
            isAddingNew = true;
        }
        ImGui::SameLine();
        if (ImGui::Button("New Contact"))
        {
            isAddingNew = true;
            selectedIndex = -1;
            memset(nameBuf.data(), 0, nameBuf.size());
            memset(nickBuf.data(), 0, nickBuf.size());
            memset(phoneBuf.data(), 0, phoneBuf.size());
            memset(emailBuf.data(), 0, emailBuf.size());
            memset(addrBuf.data(), 0, addrBuf.size());
        }
        ImGui::SameLine();
        if (ImGui::Button("Load from file"))
            manager->loadFromFile("input.txt");
        ImGui::SameLine();
        if (ImGui::Button("Save to file"))
            manager->saveToFile("output.txt");

        ImGui::EndGroup();
        ImGui::Separator();

        // left rectangle - contacts list
        ImGui::BeginChild("ContactsList", ImVec2(350, 0), true);
        auto &contacts = manager->getContacts();
        for (int i = 0; i < (int)contacts.size(); i++)
        {
            const Person &p = contacts[i];
            if (ImGui::Selectable(p.getName().c_str(), selectedIndex == i))
            {
                selectedIndex = i;
                isAddingNew = false;

                strcpy(nameBuf.data(), p.getName().c_str());
                strcpy(nickBuf.data(), p.getNickname().c_str());
                strcpy(phoneBuf.data(), p.getPhone().c_str());
                strcpy(emailBuf.data(), p.getEmail().c_str());
                strcpy(addrBuf.data(), p.getAddress().c_str());
            }
            if (i == scrollToIndex)
            {
                ImGui::SetScrollHereY();
                scrollToIndex = -1;
            }
        }
        ImGui::EndChild();
        ImGui::SameLine();

        // right rectangle - contact details
        ImGui::BeginGroup();
        ImGui::InputText("Name", nameBuf.data(), nameBuf.size());
        ImGui::InputText("Nickname", nickBuf.data(), nickBuf.size());
        ImGui::InputText("Phone", phoneBuf.data(), phoneBuf.size());
        ImGui::InputText("Email", emailBuf.data(), emailBuf.size());
        ImGui::InputText("Address", addrBuf.data(), addrBuf.size());
        ImGui::Spacing();

        // ui/ux right bottom buttons
        if (isAddingNew)
        {
            if (ImGui::Button("Add"))
            {
                manager->addContact(Person(
                    nameBuf.data(),
                    nickBuf.data(),
                    phoneBuf.data(),
                    emailBuf.data(),
                    addrBuf.data()));
                memset(nameBuf.data(), 0, nameBuf.size());
                memset(nickBuf.data(), 0, nickBuf.size());
                memset(phoneBuf.data(), 0, phoneBuf.size());
                memset(emailBuf.data(), 0, emailBuf.size());
                memset(addrBuf.data(), 0, addrBuf.size());
                showAddedPopup = true;
            }
        }
        else
        {
            if (ImGui::Button("Update"))
            {
                manager->editContact(selectedIndex, Person(
                                                        nameBuf.data(),
                                                        nickBuf.data(),
                                                        phoneBuf.data(),
                                                        emailBuf.data(),
                                                        addrBuf.data()));
                showUpdatedPopup = true;
            }
            ImGui::SameLine();
            if (ImGui::Button("Delete"))
            {
                manager->deleteContact(selectedIndex);
                selectedIndex = -1;
                isAddingNew = true;
                memset(nameBuf.data(), 0, nameBuf.size());
                memset(nickBuf.data(), 0, nickBuf.size());
                memset(phoneBuf.data(), 0, phoneBuf.size());
                memset(emailBuf.data(), 0, emailBuf.size());
                memset(addrBuf.data(), 0, addrBuf.size());
                showDeletedPopup = true;
            }
        }

        ImGui::EndGroup();
        ImGui::End();

        // popups
        if (showAddedPopup)
            ImGui::OpenPopup("Success");
        if (showUpdatedPopup)
            ImGui::OpenPopup("Updated");
        if (showDeletedPopup)
            ImGui::OpenPopup("Deleted");

        if (ImGui::BeginPopupModal("Success", NULL, ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::Text("Contact added!");
            if (ImGui::Button("OK"))
            {
                ImGui::CloseCurrentPopup();
                showAddedPopup = false;
            }
            ImGui::EndPopup();
        }
        if (ImGui::BeginPopupModal("Updated", NULL, ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::Text("Contact updated!");
            if (ImGui::Button("OK"))
            {
                ImGui::CloseCurrentPopup();
                showUpdatedPopup = false;
            }
            ImGui::EndPopup();
        }
        if (ImGui::BeginPopupModal("Deleted", NULL, ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::Text("Contact deleted!");
            if (ImGui::Button("OK"))
            {
                ImGui::CloseCurrentPopup();
                showDeletedPopup = false;
            }
            ImGui::EndPopup();
        }

        // render frame gui
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // cleanup after using
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    delete manager;
    return 0;
}
